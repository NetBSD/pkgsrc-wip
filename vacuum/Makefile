# $NetBSD: Makefile,v 1.3 2012/10/07 17:41:40 asau Exp $

DISTNAME=	vacuum-0.7
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vacuum/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apocalypse.rulez.org/vacuum
COMMENT=	Vacuum Magic, a fast-paced action game
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-SDL>=1.20.0:../../devel/p5-SDL

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
