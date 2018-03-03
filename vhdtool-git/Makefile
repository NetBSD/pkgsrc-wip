# $NetBSD$
PKGNAME=		vhdtool-0.1
CATEGORIES=		converters
GIT_REPOSITORIES=	vhdtool
GIT_REPO.vhdtool=	git://github.com/andreiw/vhdtool

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/andreiw/vhdtool
COMMENT=	Tool to convert raw .IMG files into Microsoft .VHD/.VHDX format
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-x86_64

USE_LANGUAGES=	c
USE_TOOLS+=	gmake
LDFLAGS+=	-luuid

INSTALLATION_DIRS+=		bin
INSTALLATION_DIRS+=		share/doc/${PKGBASE}

WRKSRC=	${WRKDIR}/vhdtool

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vhdtool ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../wip/mk/git-package.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
