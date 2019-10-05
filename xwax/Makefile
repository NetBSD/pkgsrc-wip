# $NetBSD$

DISTNAME=	xwax-1.7
CATEGORIES=	audio
MASTER_SITES=	https://xwax.org/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xwax.org/
COMMENT=	Vinyl emulation software
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	bash:run gsed:run gmake

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf

MAKE_FLAGS+=	EXECDIR=${PREFIX}/libexec

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
MAKE_FLAGS+=	OSS=1
.endif

REPLACE_BASH+=	scan

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting path to PREFIX in source files.
SUBST_FILES.prefix+=	import
SUBST_FILES.prefix+=	interface.c
SUBST_VARS.prefix+=	PREFIX

INSTALLATION_DIRS+=	bin libexec
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/doc/xwax

DOCFILES=	CHANGES COPYING README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xwax \
		${DESTDIR}${PREFIX}/bin/xwax
	${INSTALL_PROGRAM} ${WRKSRC}/scan \
		${DESTDIR}${PREFIX}/libexec/xwax-scan
	${INSTALL_PROGRAM} ${WRKSRC}/import \
		${DESTDIR}${PREFIX}/libexec/xwax-import
	${INSTALL_MAN} ${WRKSRC}/xwax.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xwax.1
.for file in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${file} \
		${DESTDIR}${PREFIX}/share/doc/xwax
.endfor

.include "options.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
