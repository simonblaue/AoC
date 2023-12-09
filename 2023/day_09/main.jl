

function main()

  file = "/Users/simonblaue/ownCloud/AoC/2023/day_09/testinput.txt"

  data = readlines(file)

  for line in data
    sequenze = parse.(Int,split(line, " "))
    println(sequenze)
  end
  
end



main()