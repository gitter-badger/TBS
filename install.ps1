# SFML for Visual Studio 2015
$libsUrl = "http://www.sfml-dev.org/files/SFML-2.3.2-windows-vc14-32-bit.zip"

# Paths
$rootPath = Split-Path $Script:MyInvocation.MyCommand.Path
$libsPath = Join-Path $rootPath "extern"
$zipPath  = Join-Path $libsPath "SFML-2.3.2-windows-vc14-32-bit.zip"

# Remove old and create new folder
Remove-Item -Force -Recurse $libsPath -ErrorAction SilentlyContinue
New-Item -Force -ItemType Directory $libsPath > $null

# Download SFML and extract it
Write-Host "Downloading SFML 2.3.2 lib files" -ForegroundColor Cyan
Invoke-WebRequest $libsUrl -OutFile $zipPath
[System.Reflection.Assembly]::LoadWithPartialName('System.IO.Compression.FileSystem') > $null
[System.IO.Compression.ZipFile]::ExtractToDirectory($zipPath, $libsPath)
Remove-Item $zipPath -Force -ErrorAction SilentlyContinue
