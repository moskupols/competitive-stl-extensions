all:
	latexmk -pdf -shell-escape talk

check:
	g++ -c *.cc

clean:
	rm -rf _minted-talk/ talk.{aux,fdb_latexmk,log,nav,out,snm,toc,vrb,fls} *.o *.out
