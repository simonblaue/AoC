# AoC 2023
# by Simon Blaue


# Flip-flop modules (prefix %) are either on or off; they are initially off. If a flip-flop module receives a high pulse, it is ignored and nothing happens. However, if a flip-flop module receives a low pulse, it flips between on and off. If it was off, it turns on and sends a high pulse. If it was on, it turns off and sends a low pulse.
struct FlipFlop
  state
  sends_to
end

# Conjunction modules (prefix &) remember the type of the most recent pulse received from each of their connected input modules; they initially default to remembering a low pulse for each input. When a pulse is received, the conjunction module first updates its memory for that input. Then, if it remembers high pulses for all inputs, it sends a low pulse; otherwise, it sends a high pulse.
struct Conjunction
  sends_to
  rememberd
end

struct broadcaster
  sends_to
end


function getAllModules(data)
  
  dict_of_all_modules = Dict()
  reB = r"broadcaster -> [a-z,\,,\ ]*"
  for l in data
    m = match(reB, l)
    if !isnothing(m)
        dict_of_all_modules["broadcaster"] = broadcaster([])
    else
      if l[1] == '%'
        mod_name = match(r"%(\w+) -> [a-z,\,,\ ]", l).captures[1]
        dict_of_all_modules[mod_name] = FlipFlop(false, [])
       else
         mod_name = match(r"&(\w+) -> [a-z,\,,\ ]", l).captures[1]
        dict_of_all_modules[mod_name] = Conjunction([], Dict())
       end
    end
  end
  return dict_of_all_modules
end

function fillModules(all_mods, data)

  reB = r"broadcaster -> [a-z,\,,\ ]*"
  for l in data
    m = match(reB, l)
    if !isnothing(m)
      s = l[16:end]
      while (!isnothing(match(r"(\w+)", s)))
        m = match(r"(\w+)", s)
        n = m.captures[1]
        push!(all_mods["broadcaster"].sends_to, all_mods[n])
        s = s[length(n)+3:end]
      end
    else
      if l[1] == '%'
        mod_name = match(r"%(\w+) -> [a-z,\,,\ ]", l).captures[1]

        s = l[length(mod_name)+5:end]
        while (!isnothing(match(r"(\w+)", s)))
            m = match(r"(\w+)", s)
            n = m.captures[1]
          push!(all_mods[mod_name].sends_to, all_mods[n] )
          s = s[length(n)+3:end]
        end
      else
         mod_name = match(r"&(\w+) -> [a-z,\,,\ ]", l).captures[1]
         s = l[length(mod_name)+5:end]
          while (!isnothing(match(r"(\w+)", s)))
            m = match(r"(\w+)", s)
            n = m.captures[1]
            push!(all_mods[mod_name].sends_to, all_mods[n] )
            s = s[length(n)+3:end]
          end
      end
    end
  end
  return all_mods
end

function main()
  filename = "/Users/simonblaue/ownCloud/AoC/2023/day_20/testinput.txt"
  res=-1
  data=readlines(filename)
  
  all_modules = fillModules(getAllModules(data), data)


  println(all_modules["broadcaster"])
end

main()