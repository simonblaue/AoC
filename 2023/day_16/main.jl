# AoC 2023
# by Simon Blaue


#Encode direction as top: [-1,0], east: [0,1], south: [1,0], west: [0,-1]


function move(oldPos, direction, data, marker, history)
	newPos = oldPos + direction
	nx = newPos[1]
	ny = newPos[2]
	# If we hit the border, stop or if we were there at least two times
	if nx > size(marker)[2] || nx < 1 || ny > size(marker)[1] || ny < 1
		return
	end

	if [newPos, direction] in history
		return 
	end

	push!(history, [newPos, direction])
	marker[nx, ny] += 1
	if data[nx][ny] == '.'
		move(newPos, direction, data, marker, history)
	elseif data[nx][ny] == '|'
		if direction == [-1,0] || direction == [1,0]
			move(newPos, direction, data, marker, history)
		else
			move(newPos, [1,0], data, marker, history)
			move(newPos, [-1,0],data, marker, history)
		end
	elseif data[nx][ny] == '-'
		if direction == [0,-1] || direction == [0,1]
			move(newPos, direction, data, marker, history)
		else
			move(newPos, [0,-1], data, marker, history)
			move(newPos, [0,1], data, marker, history)
		end
	elseif data[nx][ny] == '\\'
		if direction == [0,1]
			move(newPos, [1,0], data, marker, history)
		elseif direction == [0,-1]
			move(newPos, [-1,0], data, marker, history)
		elseif direction == [1,0]
			move(newPos, [0,1], data, marker, history)
		elseif direction == [-1,0]
			move(newPos, [0,-1], data, marker, history)
		else	
			println("Something went wrong,  literaly")
			return
		end
	elseif data[nx][ny] == '/'
		if direction == [0,1]
			move(newPos, [-1,0], data, marker, history)
		elseif direction == [0,-1]
			move(newPos, [1,0], data, marker, history)
		elseif direction == [1,0]
			move(newPos, [0,-1], data, marker, history)
		elseif direction == [-1,0]
			move(newPos, [0,1], data, marker, history)
		else	
			println("Something went wrong,  literaly2")
			return
		end
	else
		println("Something went wrong, literaly3")
	end
end

function main()
	 filename = "/Users/simonblaue/ownCloud/AoC/2023/day_16/input.txt"
	 res=0
	 data=readlines(filename)

	 cols = length(data[1])
	 rows = size(data)[1]
	 marker = zeros(Int8,(cols,rows))

	startPos = [1,1]
	startDir = [1,0]
	marker[startPos[1],startPos[2]] = 1
	history = [[startPos,startDir]]

	display(marker)

	move(startPos, startDir, data, marker, history)

	display(marker)

	for row in marker
		for n in row
			if n != 0
				res +=1
			end
		end
	end

	println("The result is: ", res)
end

main()