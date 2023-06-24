# $NetBSD: Makefile,v 1.19 2012/11/15 17:59:36 othyro Exp $
#

DISTNAME=	gxmms2-0.7.1
CATEGORIES=	audio
MASTER_SITES=	http://wejp.k.vu/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wejp.k.vu/projects/xmms2/
COMMENT=	Graphical GTK+2-based XMMS2 client
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

INSTALLATION_DIRS=	bin lib/gkrellm2/plugins share/doc/gxmms2/gkrellxmms2
INSTALLATION_DIRS+=	share/gxmms2

.include "../../mk/bsd.prefs.mk"
CFLAGS+=		-I${BUILDLINK_PREFIX.xmms2}/include/xmms2

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_FILES.prefix=	Makefile
SUBST_STAGE.prefix=	post-patch
SUBST_SED.prefix=	-e "s|/usr|${PREFIX}|g"
SUBST_SED.prefix+=	-e "s|/local||1"

TOOL_DEPENDS+=	gkrellm>=2.2:../../sysutils/gkrellm
.include "../../sysutils/gkrellm/buildlink3.mk"
.include "../../wip/xmms2/buildlink3.mk"
TOOL_DEPENDS+=	gtk2+>=2.6.0:../../x11/gtk2
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
