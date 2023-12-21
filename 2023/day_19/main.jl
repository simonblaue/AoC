# AoC 2023
# by Simon Blaue


struct Part
  a 
  x
  m
  s
end

function main()
  filename = "/Users/simonblaue/ownCloud/AoC/2023/day_19/testinput.txt"
  res=-1
  data=readlines(filename)
  readRules = true
  rePart = r"{x=(\d+),m=(\d+),a=(\d+),s=(\d+)}"
  parts = []
  for l in data
    if l == ""
      readRules = false
      continue
    end
    if (readRules)
      ## read the rule have fun
      println(l)
    else
      m = match(rePart, l)
      px, pm, pa, ps = m.captures
      push!(parts,Part(pa,px,pm,ps))
    end
  end


  for p in parts
    println(p.x)
  end

end

main()