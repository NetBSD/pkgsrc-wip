#############################################################

PREFIX?=	/usr/local
BINDIR?=	${PREFIX}/bin
MANDIR?=	${PREFIX}/man
DOCDIR=		${PREFIX}/share/doc/pkg_summary-utils
AWKMODDIR?=	${PREFIX}/share/awk
MKSCRIPTSDIR?=	${PREFIX}/share/psu_mk

INST_DIR?=	${INSTALL} -d

SH?=		/bin/sh
AWK?=		/usr/bin/awk

# NetBSD make is required for pkgsrc
BMAKE?=		/usr/bin/make

#############################################################

.include "Makefile.version"

SCRIPTS=	pkg_cmp_summary pkg_list_all_pkgs
SCRIPTS+=	pkg_refresh_summary pkg_src_fetch_var
SCRIPTS+=	pkg_micro_src_summary pkg_src_summary
SCRIPTS+=	pkg_update_src_summary pkg_summary4view
SCRIPTS+=	pkg_update_summary pkg_grep_summary
SCRIPTS+=	cvs_checksum pkg_assignments2pkgpath
SCRIPTS+=	pkg_uniq_summary pkg_summary2bb_pkgs

MAN=		pkg_summary-utils.7
MAN+=		pkg_cmp_summary.1 pkg_grep_summary.1
MAN+= 		pkg_micro_src_summary.1
MAN+=		pkg_src_summary.1 pkg_update_src_summary.1
MAN+=		pkg_summary4view.1 pkg_update_summary.1
MAN+=		pkg_refresh_summary.1 pkg_list_all_pkgs.1
MAN+=		cvs_checksum.1 pkg_uniq_summary.1

FILES=		README NEWS TODO pkg_grep_summary.awk pkg_src_summary.mk

FILESDIR=			${DOCDIR}
FILESDIR_pkg_grep_summary.awk=	${AWKMODDIR}
FILESDIR_pkg_src_summary.mk=	${MKSCRIPTSDIR}

BIRTHDATE=	2008-04-06

PROJECTNAME=	pkg_summary-utils

.SUFFIXES:		.in

.in:
	sed -e 's,@@sysconfdir@@,${SYSCONFDIR},g' \
	    -e 's,@@libexecdir@@,${LIBEXECDIR},g' \
	    -e 's,@@prefix@@,${PREFIX},g' \
	    -e 's,@@bindir@@,${BINDIR},g' \
	    -e 's,@@sbindir@@,${SBINDIR},g' \
	    -e 's,@@datadir@@,${DATADIR},g' \
	    -e 's,@@version@@,${VERSION},g' \
	    -e 's,@@awkmoddir@@,${AWKMODDIR},g' \
	    -e 's,@@mkscriptsdir@@,${MKSCRIPTSDIR},g' \
	    -e 's,@SH@,${SH},g' \
	    -e 's,@AWK@,${AWK},g' \
	    ${.ALLSRC} > ${.TARGET} && chmod +x ${.TARGET}

.PHONY: clean-my
clean: clean-my
clean-my:
	rm -f ChangeLog ${SCRIPTS} *.cat1 *.cat7

############################################################
.PHONY: install-dirs
install-dirs:
	$(INST_DIR) ${DESTDIR}${BINDIR}
	$(INST_DIR) ${DESTDIR}${DOCDIR}
	$(INST_DIR) ${DESTDIR}${AWKMODDIR}
	$(INST_DIR) ${DESTDIR}${MKSCRIPTSDIR}
.if "$(MKMAN)" != "no"
	$(INST_DIR) ${DESTDIR}${MANDIR}/man1
	$(INST_DIR) ${DESTDIR}${MANDIR}/man7
.if "$(MKCATPAGES)" != "no"
	$(INST_DIR) ${DESTDIR}${MANDIR}/cat1
	$(INST_DIR) ${DESTDIR}${MANDIR}/cat7
.endif
.endif

############################################################

.PHONY : test
test : all
	@echo 'running tests...'; \
	if cd ${.CURDIR}/tests && \
		env PATH="${.OBJDIR}:$$PATH" OBJDIR=${.OBJDIR} \
			BMAKE=${BMAKE} ./test.sh \
			> ${.OBJDIR}/_test.res && \
		diff -C10 ${.CURDIR}/tests/test.out ${.OBJDIR}/_test.res; \
	then echo '   succeeded'; \
	else echo '   failed'; false; \
	fi

############################################################

.include <bsd.prog.mk>
