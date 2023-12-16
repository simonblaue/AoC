# AoC 2023
# by Simon Blaue


function myhash(line)
	value = 0
	for c in line
		value += Int(c)
		value *= 17
		value %= 256
	end
	return value
end

function main()
	 filename = "/Users/simonblaue/ownCloud/AoC/2023/day_15/input.txt"
	 res=0
	 data=readline(filename)

	value = 0
	for c in data
		if c==','
			res += value
			value = 0
			continue
		end
		value += Int(c)
		value *= 17
		value = value % 256
	end
	res += value

	println(myhash("HASH"))

	 println("The result is: ", res)
end

main()