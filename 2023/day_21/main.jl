# by Simon Blaue
# AoC 2023

function getValidNeigbourhPlots(p,map)
  pns = []
  rows, cols = size(map)
  MaPCordSet = Set([CartesianIndex(i,j) for i=1:rows, j=1:cols])
  ps = [
    (p+CartesianIndex(1,0)),
    (p+CartesianIndex(-1,0)),
    (p+CartesianIndex(0,-1)),
    (p+CartesianIndex(0,1))]

  for p in ps
    if (p in MaPCordSet && map[p]=='.')
      push!(pns, p)
    end
  end
  return pns
end

function step!(map)
   ps = findall(map .== 'O')
   for p in ps
    map[p] = '.'
    for pn in getValidNeigbourhPlots(p, map)
      map[pn] = 'O'
    end
   end
end

function main()
  filename = "/Users/simonblaue/ownCloud/AoC/2023/day_21/input.txt"
  maxsteps = 64
  map=stack(readlines(filename))
  sp = findfirst(map .== 'S')
  map[sp] = '.'
  for pn in getValidNeigbourhPlots(sp, map)
      map[pn] = 'O'
  end

  for _ in 2:maxsteps
    step!(map)
  end

  
  display(map)

  n = length(findall(map .== 'O'))
  println("result: ", n)
end

main()