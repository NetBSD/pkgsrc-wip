############################################################

PREFIX?=/usr/local
AWKMODDIR?=${PREFIX}/share/awk

INST_DIR?=	${INSTALL} -d

############################################################

.include "Makefile.version"

FILES=		pkgsrc-dewey.awk

FILESDIR=	${AWKMODDIR}

MKMAN=		no

BIRTHDAY=	2008-02-20

PROJECTNAME=	pkg_cmp_summary

############################################################
.PHONY: install-dirs
install-dirs:
	$(INST_DIR) ${DESTDIR}${BINDIR}
.if "$(MKMAN)" != "no"
	$(INST_DIR) ${DESTDIR}${MANDIR}/man1
.if "$(MKCATPAGES)" != "no"
	$(INST_DIR) ${DESTDIR}${MANDIR}/cat1
.endif
.endif

############################################################
.PHONY : test
test:
	runawk tests.awk < tests.txt

############################################################

.sinclude "Makefile.cvsdist"

.include <bsd.prog.mk>
