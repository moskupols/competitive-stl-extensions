all:
	latexmk -pdf -shell-escape talk

clean:
	rm -rf _minted-talk/ talk.{aux,fdb_latexmk,log,nav,out,snm,toc,vrb,fls}
