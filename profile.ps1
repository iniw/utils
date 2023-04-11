Set-Alias pio platformio

function gs {
	git status $args
}

function ga {
	git add $args
}

function gap {
	git add -p $args
}

function gr {
	git rebase $args
}

function grs {
	git restore $args
}

function grt {
	git reset $args
}

Remove-Alias -Name gc -Force
function gc {
	git commit $args
}

function gd {
	git difftool $args
}

function glo {
	git log --oneline $args
}

Invoke-Expression (&starship init powershell)
