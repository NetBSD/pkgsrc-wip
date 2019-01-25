# $NetBSD$

DISTNAME=	mmail-0.51
CATEGORIES=	news
MASTER_SITES=	https://downloads.sourceforge.net/project/multimail/MultiMail/0.51/

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://multimail.sourceforge.io/
COMMENT=	Offline mail reader for Blue Wave, QWK, OMEN, SOUP and OPX
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

AUTO_MKDIRS=		yes
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
