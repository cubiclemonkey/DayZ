do{
    $running = Get-Process DayZServer* -ErrorAction SilentlyContinue
    if ($running) {
		$currentdate = Get-Date
		# Set og file for interval history
		$intervallog = "C:\Users\bigcountry\Documents\process\logs\interval.log"
		# Set log file for count history
		$countlog = "C:\Users\bigcountry\Documents\process\logs\count.log"
		# Get a random integer to set the update interval
		$updatein = Get-Random -Minimum 48 -Maximum 721
		# Logs the interval to the specified path
		$updatein | Out-File -FilePath $intervallog -Append
		# Outputs to the Powershell window
		Write-Host "Next update in" $updatein":" $currentdate
		Start-Sleep -Seconds $updatein
			# Get a random integer to set the player count to
			$updateco = Get-Random -Minimum 0 -Maximum 8
			# Changes the player count
			Set-Content -Path .\dzfake.txt -Value $updateco
			$updateco | Out-File -FilePath $countlog -Append
			Write-Host "Player Count Updated" $updateco $currentdate
    }
	if (!$running) {
	Start-Sleep -Seconds 90
	}
} while (1 -eq 1)
