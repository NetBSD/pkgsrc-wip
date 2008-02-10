############################################################

PREFIX?=/usr/local
BINDIR?=${PREFIX}/bin
MANDIR?=${PREFIX}/man

INST_DIR?=	${INSTALL} -d

############################################################

SCRIPTS=	pkg_cmp_summary
MAN=		pkg_cmp_summary.1

VERSION=	0.2.0

BIRTHDAY=	2008-02-11

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

.sinclude "Makefile.cvsdist"

.include <bsd.prog.mk>
