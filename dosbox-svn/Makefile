# $NetBSD$

DISTNAME=	dosbox-svn-0
CATEGORIES=	emulators

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dosbox.com/
COMMENT=	Multi-platform DOS emulator using SDL
LICENSE=	gnu-gpl-v2

SVN_REPO=	https://svn.code.sf.net/p/dosbox/code-0/dosbox/trunk

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS.Darwin+=	--disable-dynrec
CPPFLAGS.SunOS+=	-DDISABLE_JOYSTICK
.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mclang*)
CPPFLAGS+=		-fPIC
.endif
LDFLAGS.SunOS+=		-lsocket
INSTALLATION_DIRS=	share/doc/dosbox

USE_TOOLS+=	autoconf automake

SUBST_CLASSES+=		fixme
SUBST_STAGE.fixme=	post-patch
SUBST_FILES.fixme=	docs/dosbox.1
SUBST_SED.fixme=	-e s,/usr/share/,${PREFIX}/share/,g

NOT_PAX_MPROTECT_SAFE+=	bin/dosbox

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/dosbox

.include "../../wip/mk/svn-package.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
