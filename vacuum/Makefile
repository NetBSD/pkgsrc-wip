# $NetBSD: Makefile,v 1.1.1.1 2008/11/18 13:22:55 thomasklausner Exp $
#

DISTNAME=	vacuum-0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vacuum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apocalypse.rulez.org/vacuum
COMMENT=	Vacuum Magic, a fast-paced action game

DEPENDS+=	p5-SDL>=1.20.0:../../devel/p5-SDL
DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	perl
REPLACE_PERL=	bin/vacuum

SUBST_CLASSES+=		data
SUBST_SED.data=		-e "s,/usr/local/share/vacuum,${PREFIX}/share/vacuum,"
SUBST_FILES.data=	bin/vacuum
SUBST_MESSAGE.data=	Fixing path to data directory.
SUBST_STAGE.data=	post-configure

.include "../../mk/bsd.pkg.mk"
