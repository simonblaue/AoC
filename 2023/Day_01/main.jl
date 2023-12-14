# AoC 2023
# by Simon Blaue

# On each line, the calibration value can be found by combining the first digit and the last digit (in that order) to form a single two-digit number.

function main()
  
  filename = "day_01/input.txt"
  res = 0
  data = readlines(filename)

  re1 = r"(\d)[a-z,0-9]*"
  re2 = r"[a-z,0-9]*(\d)"
  
  for line in data
    m1 = match(re1, line)
    m2 = match(re2, m1.match[2:end])

    firstNum = parse(Int,m1.captures[1])
    if (m2 != nothing)
      if (m2.captures != Nothing)
        secondNum = parse(Int,m2.captures[1])
      end
    else
      secondNum = firstNum
    end

    num = firstNum*10+secondNum
    res += num
  end
  
  println("The result is: ", res)

end


@time main()