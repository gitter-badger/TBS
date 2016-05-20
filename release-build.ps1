$defines = @{ }
$defineString = ""
$defines["ASSET_DIR"] = ".\\Assets\\"

foreach ($key in $defines.Keys) {
	$value = $defines[$key]
	if ($value -is [System.String]) {
		$value = $value.Replace('"', '\"')
	}
	$defineString += "$key=""$value"";"
}

# Store the definestring in an environment varibale for the solution to read: $(TBS_DEFINES)
$env:TBS_DEFINES = $defineString
$msbuild = Join-Path ${env:ProgramFiles(x86)} "MSBuild\14.0\Bin\amd64\MSBuild.exe"
&$msbuild /v:minimal /p:Configuration=Release /t:rebuild
