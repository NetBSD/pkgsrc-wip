# $NetBSD: Makefile,v 1.1 2013/12/11 19:13:31 outpaddling Exp $

DISTNAME=	Lmod-5.2
CATEGORIES=	sysutils
MASTER_SITES=	http://downloads.sourceforge.net/project/lmod/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://downloads.sourceforge.net/project/lmod/
COMMENT=	Dynamic modification of a user's environment
LICENSE=	mit

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	${LUA_PKGPREFIX}-filesystem-[0-9]*:../../devel/lua-filesystem
DEPENDS+=	${LUA_PKGPREFIX}-posix-[0-9]*:../../devel/lua-posix
.if ${OPSYS} != "Linux"	# Part of base on CentOS and zsh pkg does not build
DEPENDS+=	zsh-[0-9]*:../../shells/zsh
.endif

WRKSRC=		${WRKDIR}/Lmod-5.2
GNU_CONFIGURE=	yes
MAKE_FILE=	makefile
USE_TOOLS+=	gmake

post-install:
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	${LN} -s ${DESTDIR}${PREFIX}/lmod/5.2/libexec/lmod \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/lua/application.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
