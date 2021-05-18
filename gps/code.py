def generate_code(prn, taps, output_path = 'log.txt'):
	g1_arr = [1] * 10
	g2_arr = [1] * 10

	f = open(output_path, 'w')
	for i in range(1023):
		# g1
		g1_arr = [g1_arr[2] ^ g1_arr[9]] + g1_arr[:9]
		# g2
		new_g2_bit = (g2_arr[5] ^ g2_arr[7] ^ g2_arr[8] ^ g2_arr[9]) ^ (g2_arr[1] ^ g2_arr[2])
		g2_arr = [new_g2_bit] + g1_arr[:9]
		# ca
		prn_bit = g2_arr[taps[prn-1][0] - 1] ^ g2_arr[taps[prn-1][1] - 1]
		CAbit = g1_arr[-1] ^ prn_bit
		f.write(str(CAbit))
		#print(CAbit, end='')
