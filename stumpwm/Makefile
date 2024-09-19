# $NetBSD: Makefile,v 1.12 2012/11/03 19:41:30 kristerw Exp $
#

SHORTNAME=		stumpwm
VERSION=		0.9.7
PKGNAME=		${SHORTNAME}-${VERSION}
DISTNAME=		${PKGNAME}
CATEGORIES=		wm
DISTFILES=		${DISTNAME}.tgz
SITES.${DISTNAME}.tgz=	http://download.savannah.nongnu.org/releases/stumpwm/

MAINTAINER=		jfranz@bsdprojects.net
HOMEPAGE=		https://www.nongnu.org/stumpwm/
COMMENT=		Tiling, keyboard driven X11 Window Manager written in Common Lisp
LICENSE=		gnu-gpl-v2

.include "options.mk"

USE_TOOLS+=		autoconf make makeinfo install-info
.if !empty(PKG_OPTIONS:Mclisp)
# clisp-core target, until CLISP 2.50 release
USE_LANGUAGES=		c
USE_GNU_READLINE=	yes
.endif
INSTALLATION_DIRS+=	${PKGINFODIR} bin
INFO_FILES=		yes
INSTALL_UNSTRIPPED=	yes

DEPENDS=		sudo-[0-9]*:../../security/sudo
.if !empty(PKG_OPTIONS:Mclisp)
LISP_CENTRAL_REGISTRY=	${CLISP_CENTRAL_REGISTRY}
# X11 bindings
DEPENDS+=		clisp-new-clx>=2.42:../../x11/clisp-new-clx
.endif
.if !empty(PKG_OPTIONS:Msbcl)
LISP_CENTRAL_REGISTRY=	${SBCL_CENTRAL_REGISTRY}
DEPENDS+=		sbcl-portable-clx-[0-9]*:../../wip/cl-portable-clx
.endif
# From README: "by default stumpwm elects sbcl"
.if !empty(PKG_OPTIONS:Mclisp)
CONFIGURE_ARGS=		--with-lisp=clisp
.endif

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-extract
SUBST_FILES.sysconf=	stumpwm.asd
SUBST_SED.sysconf=	-e 's/version "CVS"/version "${VERSION}"/'

SED_EXPRS=		-e "s\#asdf_path\#${PREFIX}/${LISP_CENTRAL_REGISTRY}\#"
.if !empty(PKG_OPTIONS:Mclisp)
SED_EXPRS+=		-e "s/expr_param/-x/"
SED_EXPRS+=		-e "s/mem_param/-M/"
SED_EXPRS+=		-e "s/lisp_comp/clisp/"
SED_EXPRS+=		-e "s\#lisp_cmd\#-q -norc -x '(require \\\\\"clx\\\\\")'\#"
# clisp-core target
SED_EXPRS+=		-e "s\#\(clisp_core_temp=\"\)\#\1-K${PREFIX}/${LISP_CENTRAL_REGISTRY}${SHORTNAME}/clisp-core\#"
SED_EXPRS+=		-e "s/used_save_cmd/clisp_save_cmd/"
.endif
.if !empty(PKG_OPTIONS:Msbcl)
SED_EXPRS+=		-e "s/expr_param/--eval/"
SED_EXPRS+=		-e "s/mem_param/--core/"
SED_EXPRS+=		-e "s/lisp_comp/sbcl/"
SED_EXPRS+=		-e "s/lisp_cmd/--disable-debugger --non-interactive/"
SED_EXPRS+=		-e "s/used_save_cmd/sbcl_save_cmd/"
.endif

post-extract:
	${LN} -s ${WRKSRC}/cl-ppcre/cl-ppcre.asd ${WRKSRC}/cl-ppcre.asd
.if !empty(PKG_OPTIONS:Mclisp)
	${RM} ${WRKSRC}/asdf.lisp
	@${ECHO} '(progn (require "clx"))' >> ${WRKSRC}/stumpwm.asd
	${LN} -s ${PREFIX}/lib/clisp/dynmod/clx.lisp ${WRKSRC}/clx.lisp
.endif

do-configure:
	cd ${WRKSRC} && autoconf && \
		./configure ${CONFIGURE_ARGS} && ${MAKE} stumpwm.info

	${SED} ${SED_EXPRS} ${FILESDIR}/${SHORTNAME} > ${WRKSRC}/stumpwm
.if !empty(PKG_OPTIONS:Mclisp)
	cd ${WRKSRC} && ${MAKE} clisp-core
.endif

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/stumpwm ${DESTDIR}${PREFIX}/bin/stumpwm
	${INSTALL_MAN} ${WRKSRC}/stumpwm.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/stumpwm.info
	# Stumpwm is distributed not like just cl package, but like normal software, so move out the junk
	mkdir -p ${DESTDIR}${PREFIX}/${LISP_CENTRAL_REGISTRY}/${SHORTNAME}-dest/cl-ppcre
	cd ${DESTDIR}${PREFIX}/${LISP_CENTRAL_REGISTRY}${SHORTNAME} && ${MV} stumpwm.asd *.lisp *.fas* contrib ../${SHORTNAME}-dest/ && \
		${MV} cl-ppcre/cl-ppcre.asd cl-ppcre/*.lisp cl-ppcre/*.fas* ../${SHORTNAME}-dest/cl-ppcre/
	# ASDF requires .fasl files write dates to be more fresh than .lisp ones, or recompilation will be done.
	# Do hardlinks of *.lisp from sources directory to return original dates.
.if !empty(PKG_OPTIONS:Mclisp)
	# As we don't need it after the build is done, remove it to prevent possible "cross-device link" error
	${RM} ${WRKSRC}/clx.lisp
.endif
	${LN} -f ${WRKSRC}/cl-ppcre/*.lisp ${DESTDIR}${PREFIX}/${LISP_CENTRAL_REGISTRY}/${SHORTNAME}-dest/cl-ppcre/
	${LN} -f ${WRKSRC}/*.lisp ${DESTDIR}${PREFIX}/${LISP_CENTRAL_REGISTRY}/${SHORTNAME}-dest/
.if !empty(PKG_OPTIONS:Mclisp)
	mkdir ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}/${SHORTNAME}-dest/clisp-core
	cd ${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME} && ${MV} clisp-core/lispinit.mem \
		../${SHORTNAME}-dest/clisp-core
.endif
	${RM} -r ${DESTDIR}${PREFIX}/${LISP_CENTRAL_REGISTRY}${SHORTNAME}/
	${MV} ${DESTDIR}${PREFIX}/${LISP_CENTRAL_REGISTRY}/${SHORTNAME}-dest/ ${DESTDIR}${PREFIX}/${LISP_CENTRAL_REGISTRY}${SHORTNAME}
.if !empty(PKG_OPTIONS:Mclisp)
	${INSTALL_PROGRAM} ${WRKSRC}/clisp-core/lisp.run \
		${DESTDIR}${PREFIX}/${CLISP_CENTRAL_REGISTRY}${SHORTNAME}/clisp-core/lisp.run

# clisp-core target
.include "../../wip/mk/clisp-temp.mk"
.endif
.include "../../wip/mk/cl-package.mk"
.include "../../mk/bsd.pkg.mk"
