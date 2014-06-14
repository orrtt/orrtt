
fun! s:c_style()
	set ts=2
	set st=2
	set sw=2
	set et
endfun!

fun! s:makefile_style()
	setlocal ts=4
	setlocal st=4
	setlocal sw=4
	setlocal noet
endfun!


autocmd FileType c call s:c_style()
autocmd FileType cpp call s:c_style()
autocmd FileType make call s:makefile_style()
autocmd FileType automake call s:makefile_style()

let g:ycm_confirm_extra_conf=0
