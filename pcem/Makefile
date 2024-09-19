# $NetBSD$

DISTNAME=	PCemV17Linux
PKGNAME=	${DISTNAME:S/Linux$//1:S/V/-/1:tl}
CATEGORIES=	emulators
MASTER_SITES=	https://pcem-emulator.co.uk/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pcem-emulator.co.uk/
COMMENT=	Emulator for various IBM PC computers and clones
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

WRKSRC=		${WRKDIR}
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CPPFLAGS.NetBSD+=	-Doff64_t=off_t

CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ARGS+=	--disable-sdlframework

.include "options.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
