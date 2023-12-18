# AoC 2023
# by Simon Blaue

using Plots, LinearAlgebra

function getNeighbours(p)
	return [
		[p[1]-1,p[2]],
		[p[1]+1,p[2]],
		[p[1],p[2]-1],
		[p[1],p[2]+1]
	]
end

function inbound(field, p)
	rows, cols = size(field)
	if p[1] < rows && p[1]>0 && p[2] < cols-1 && p[2]>0
		return true
	end
	return false
end

function fillConture!(p, field, inner)
	inner[p[1], p[2]] = 1
	neigbours = getNeighbours(p)
	for n in neigbours
		if inbound(field, n)
			if field[n[1],n[2]] == 0 && inner[n[1],n[2]] == 0
				fillConture!(n, field, inner)
			end
		end
	end
end

function try_one(data)
	contour = zeros(Int, 400,800)
	i = 1
	pos = [300,300]
	for l in data
		dir = l[1]
		amount = parse(Int,l[3])
		if dir == 'R'
			contour[pos[1], pos[2]:pos[2]+amount] .= i
			pos += [0, amount]
		elseif dir == 'L'
			contour[pos[1], pos[2]-amount:pos[2]] .= i
			pos += [0,-amount]
		elseif dir == 'D'
			contour[pos[1]:pos[1]+amount, pos[2]] .= i
			pos += [amount, 0]
		elseif dir == 'U'
			contour[pos[1]-amount:pos[1], pos[2]] .= i
			pos += [-amount,0]
		end
	end

	inner = zeros(Int,size(contour))

	display(contour)
	display(plot(heatmap(contour, color=:grays, aspect_ratio=1)))
	fillConture!([200,200], contour, inner)
	display(plot(heatmap(contour+inner, color=:grays, aspect_ratio=1)))
	println("The result is: ", sum(contour + inner))
end

function main()

	filename = "/Users/simonblaue/ownCloud/AoC/2023/day_18/input.txt"
	data=readlines(filename)
	
	pxs = [1]
	pys = [1]
	pos = [1,1]
	contourlen = 0
	for l in data 
		dir = l[1]
		amount = parse(Int,l[3])
		if dir == 'R'
			pos += [0, amount]
		elseif dir == 'L'
			pos += [0,-amount]
		elseif dir == 'D'
			pos += [amount, 0]
		elseif dir == 'U'
			pos += [-amount,0]
		end
		push!(pys, pos[1])
		push!(pxs, pos[2])
		contourlen += amount
	end

	p1 = plot(pxs,pys)


	area = 0
	for (pxi,pyi,pxi1,pyi1) in zip(pxs[1:end-1],pys[1:end-1],pxs[2:end], pys[2:end])
		area += (pyi+pyi1)*(pxi-pxi1)
	end
	area /= 2

	println(contourlen)
	println(area)
	println(area+1+contourlen/2)



	display(p1)
end



main()