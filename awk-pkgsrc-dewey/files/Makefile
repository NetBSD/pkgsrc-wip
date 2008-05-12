############################################################

PREFIX?=	/usr/local
AWKMODDIR?=	${PREFIX}/share/awk
DOCDIR=		${PREFIX}/share/doc/awk-pkgsrc-dewey

INST_DIR?=	${INSTALL} -d

############################################################

.include "Makefile.version"

FILES=		NEWS pkgsrc-dewey.awk

FILESDIR=	${AWKMODDIR}
FILESDIR_NEWS=	${DOCDIR}

MKMAN=		no

BIRTHDATE=	2008-02-20

PROJECTNAME=	awk-pkgsrc-dewey

############################################################
.PHONY: install-dirs
install-dirs:
	$(INST_DIR) ${DESTDIR}${DOCDIR}
	$(INST_DIR) ${DESTDIR}${AWKMODDIR}
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
