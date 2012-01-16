# $NetBSD: Makefile,v 1.3 2012/01/16 11:10:49 asau Exp $

PKGNAME=	clisp-${SHORTNAME}-${VER}
SHORTNAME=	asdf
CATEGORIES=	devel
MASTER_SITES=	http://www.kozachuk.info/netbsd/contrib/
VER=		2.018.19
DISTNAME=	${SHORTNAME}-${VER}

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/asdf/
COMMENT=	Another System Definition Facility for Common Lisp
LICENSE=	mit

DEPENDS+=	clisp>=2.49:../../lang/clisp
PKG_DESTDIR_SUPPORT= user-destdir
CHECK_PORTABILITY_SKIP= bin/asdf-version bin/make-tarball
USE_TOOLS+=	makeinfo
INFO_FILES=	yes
INSTALLATION_DIRS= \
		lib/clisp/dynmod \
		lib/clisp/asdfmod \
		share/doc/${PKGNAME} \
		${PKGINFODIR}
PLIST_SUBST+=	NAME="${PKGNAME}"
PLIST_SUBST+=	INFODIR="${PKGINFODIR}"

do-build:
	( cd ${WRKSRC} && \
	    ${MV} asdf.lisp asdf.lisp.orig && \
	    ${SED} "s+#p\"/etc/common-lisp/\"+#p\"${PREFIX}/lib/clisp/\"+" asdf.lisp.orig > asdf.lisp && \
	    ${PREFIX}/bin/clisp -q -norc -c asdf.lisp )
	echo "(:source-registry (:tree \"${PREFIX}/lib/clisp/asdfmod/\") :inherit-configuration)" >${WRKSRC}/source-registry.conf
	echo "(:output-translations (t t) :inherit-configuration)" >${WRKSRC}/asdf-output-translations.conf
	( cd ${WRKSRC}/doc && ${MAKEINFO} --html --no-split --no-headers -o asdf.html asdf.texinfo )
	( cd ${WRKSRC}/doc && ${MAKEINFO} asdf.texinfo )

do-install:
	${INSTALL_DATA} ${WRKSRC}/asdf.lisp ${DESTDIR}${PREFIX}/lib/clisp/dynmod/asdf.lisp
	${INSTALL_DATA} ${WRKSRC}/asdf.fas ${DESTDIR}${PREFIX}/lib/clisp/dynmod/asdf.fas
	${INSTALL_DATA} ${WRKSRC}/source-registry.conf ${DESTDIR}${PREFIX}/lib/clisp/source-registry.conf
	${INSTALL_DATA} ${WRKSRC}/asdf-output-translations.conf ${DESTDIR}${PREFIX}/lib/clisp/asdf-output-translations.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/README
	${INSTALL_DATA} ${WRKSRC}/doc/asdf.html ${DESTDIR}${PREFIX}/share/doc/${PKGNAME}/asdf.html
	${INSTALL_DATA} ${WRKSRC}/doc/asdf.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/asdf.info

.include "../../mk/bsd.pkg.mk"
