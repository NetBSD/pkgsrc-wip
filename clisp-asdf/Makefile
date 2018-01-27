# $NetBSD: Makefile,v 1.8 2012/09/24 18:26:54 asau Exp $

DISTNAME=	asdf-2.018.19
PKGNAME=	clisp-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.kozachuk.info/netbsd/contrib/

MAINTAINER=	ddeus.pkgsrc@mailnull.com
HOMEPAGE=	http://common-lisp.net/project/asdf/
COMMENT=	Another System Definition Facility for Common Lisp
LICENSE=	mit

DEPENDS+=	clisp>=2.49:../../lang/clisp

USE_TOOLS+=	makeinfo
INFO_FILES=	yes

PKG_SYSCONFSUBDIR=	clisp

INSTALLATION_DIRS= \
		lib/clisp/dynmod \
		lib/clisp/asdfmod \
		share/doc/${PKGNAME_NOREV} \
		share/examples/${PKGBASE} \
		${PKGINFODIR}

CONF_FILES+=	share/examples/${PKGBASE}/source-registry.conf \
		${PKG_SYSCONFDIR}/source-registry.conf
CONF_FILES+=	share/examples/${PKGBASE}/asdf-output-translations.conf \
		${PKG_SYSCONFDIR}/asdf-output-translations.conf

CHECK_PORTABILITY_SKIP=	bin/asdf-version bin/make-tarball

do-build:
	( cd ${WRKSRC} && \
	    ${MV} asdf.lisp asdf.lisp.orig && \
	    ${SED} "s+#p\"/etc/common-lisp/\"+#p\"${PKG_SYSCONFDIR}/\"+" asdf.lisp.orig > asdf.lisp && \
	    ${PREFIX}/bin/clisp -q -norc -c asdf.lisp )
	echo "(:source-registry (:tree \"${PREFIX}/lib/clisp/asdfmod/\") :inherit-configuration)" >${WRKSRC}/source-registry.conf
	echo "(:output-translations (t t) :inherit-configuration)" >${WRKSRC}/asdf-output-translations.conf
	( cd ${WRKSRC}/doc && ${MAKEINFO} --html --no-split --no-headers -o asdf.html asdf.texinfo )
	( cd ${WRKSRC}/doc && ${MAKEINFO} asdf.texinfo )

do-install:
	${INSTALL_DATA} ${WRKSRC}/asdf.lisp ${DESTDIR}${PREFIX}/lib/clisp/dynmod/asdf.lisp
	${INSTALL_DATA} ${WRKSRC}/asdf.fas ${DESTDIR}${PREFIX}/lib/clisp/dynmod/asdf.fas
	${INSTALL_DATA} ${WRKSRC}/source-registry.conf ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/source-registry.conf
	${INSTALL_DATA} ${WRKSRC}/asdf-output-translations.conf ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}/asdf-output-translations.conf
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}/README
	${INSTALL_DATA} ${WRKSRC}/doc/asdf.html ${DESTDIR}${PREFIX}/share/doc/${PKGNAME_NOREV}/asdf.html
	${INSTALL_INFO} ${WRKSRC}/doc/asdf.info ${DESTDIR}${PREFIX}/${PKGINFODIR}/asdf.info

.include "../../mk/bsd.pkg.mk"
