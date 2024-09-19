# $NetBSD$

DISTNAME=	urw-base35-ttf-20170801.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=ArtifexSoftware/}
GITHUB_PROJECT=	urw-base35-fonts
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ArtifexSoftware/urw-base35-fonts/
COMMENT=	URW++ base 35 font set
LICENSE=	gnu-agpl-v3

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
FCEGDIR=	${EGDIR}/fontconfig-conf.d
FCCFDIR=	${PKG_SYSCONFDIR}/fontconfig/conf.d

MAKE_DIRS+=	${FCCFDIR}

CONF_FILES+=	${FCEGDIR}/68-urw-bookman.conf	\
		${FCCFDIR}/68-urw-bookman.conf
CONF_FILES+=	${FCEGDIR}/68-urw-c059.conf	\
		${FCCFDIR}/68-urw-c059.conf
CONF_FILES+=	${FCEGDIR}/68-urw-d050000l.conf	\
		${FCCFDIR}/68-urw-d050000l.conf
CONF_FILES+=	${FCEGDIR}/68-urw-fallback-backwards.conf	\
		${FCCFDIR}/68-urw-fallback-backwards.conf
CONF_FILES+=	${FCEGDIR}/68-urw-fallback-generics.conf	\
		${FCCFDIR}/68-urw-fallback-generics.conf
CONF_FILES+=	${FCEGDIR}/68-urw-fallback-specifics.conf	\
		${FCCFDIR}/68-urw-fallback-specifics.conf
CONF_FILES+=	${FCEGDIR}/68-urw-gothic.conf	\
		${FCCFDIR}/68-urw-gothic.conf
CONF_FILES+=	${FCEGDIR}/68-urw-nimbus-mono-ps.conf	\
		${FCCFDIR}/68-urw-nimbus-mono-ps.conf
CONF_FILES+=	${FCEGDIR}/68-urw-nimbus-roman.conf	\
		${FCCFDIR}/68-urw-nimbus-roman.conf
CONF_FILES+=	${FCEGDIR}/68-urw-nimbus-sans.conf	\
		${FCCFDIR}/68-urw-nimbus-sans.conf
CONF_FILES+=	${FCEGDIR}/68-urw-p052.conf	\
		${FCCFDIR}/68-urw-p052.conf
CONF_FILES+=	${FCEGDIR}/68-urw-standard-symbols-ps.conf	\
		${FCCFDIR}/68-urw-standard-symbols-ps.conf
CONF_FILES+=	${FCEGDIR}/68-urw-z003.conf	\
		${FCCFDIR}/68-urw-z003.conf

REQD_DIRS=	${EGDIR}
REQD_DIRS+=	${FCEGDIR}

INSTALLATION_DIRS=	share/fonts/X11/TTF ${FCEGDIR}

pre-install:
	${RUN}				\
	cd ${WRKSRC}/fontconfig/;	\
	for c in *.conf; do		\
		${MV} "$$c" "68-$$c";	\
	done

do-install:
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/fontconfig/*.conf ${DESTDIR}${FCEGDIR}

.include "../../mk/bsd.pkg.mk"
