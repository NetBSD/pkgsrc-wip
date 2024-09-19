# $NetBSD$

DISTNAME=	gr-gsm-0.42.2
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_GITHUB:=ptrkrysik/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ptrkrysik/gr-gsm/
COMMENT=	Gnuradio blocks and tools for receiving GSM transmissions
LICENSE=	gnu-gpl-v3

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

DEPENDS+=	gnuradio-companion-[0-9]*:../../ham/gnuradio-companion
DEPENDS+=	gnuradio-qtgui-[0-9]*:../../ham/gnuradio-qtgui

PY_PATCHPLIST=	yes

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../ham/gnuradio-core/buildlink3.mk"
.include "../../ham/gnuradio-digital/buildlink3.mk"
.include "../../ham/gnuradio-utils/buildlink3.mk"
.include "../../ham/gr-osmosdr/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/libosmocore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
