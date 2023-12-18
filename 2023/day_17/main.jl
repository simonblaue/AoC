# AoC 2023
# by Simon Blaue


function min_cost_route(cost_matrix)
    rows, cols = size(cost_matrix)
    
    # Initialize a 2D array to store the minimum cost for each position
    dp = zeros(Int, rows, cols)
    
    # Initialize the first column steps 
    for i in 2:4
			direct_cost = sum(cost_matrix[1, 2:i])
			dtc1 = sum(cost_matrix[2, 1:i]) + cost_matrix[1,i]
			# dtc2 =  sum(cost_matrix[2, 2:i]) + cost_matrix[1,i] + cost_matrix[1,2] 
			dtc3 = Inf
			if i>3
				dtc3  = sum(cost_matrix[2, 3:i]) + cost_matrix[1,i] + cost_matrix[1,3] 
			end
			min_detour_cost = minimum([dtc1, dtc3])

      dp[i, 1] = minimum([direct_cost, min_detour_cost] )
    end
    
    # Initialize the first row steps
		for i in 2:4
			direct_cost = sum(cost_matrix[2:i,1])
			dtc1 = sum(cost_matrix[1:i,2]) + cost_matrix[i,1]
			# dtc2 =  sum(cost_matrix[2:i, 2]) + cost_matrix[i, 1] + cost_matrix[2,1] 
			dtc3 = Inf
			if i > 3 
				dtc3  = sum(cost_matrix[3:i,2]) + cost_matrix[i,1] + cost_matrix[3,1] 
			end
			min_detour_cost = minimum([dtc1, dtc3])

      dp[1, i] = minimum([direct_cost, min_detour_cost] )
    end
    

		display(dp)

    # Fill in the DP table
    for i in 1:rows
        for j in 1:cols
          if (i<4 && j == 1) || (j<4 && i == 1)
            continue
          end
            # Calculate the minimum cost based on the allowed moves
            dp[i, j] = cost_matrix[i, j] + min(
                dp[i-1, j],
                dp[i, j-1],
            )
        end
    end

		display(dp)
    
    return dp[rows, cols]
end

function main()
	filename = "/Users/simonblaue/ownCloud/AoC/2023/day_17/testinput.txt"
	data=readlines(filename)
	arr = stack([[parse(Int, i) for i in line] for line in data])

	println(arr[1,2])

	
	res = min_cost_route(arr)

	# println("The result is: ", res)
end

main()