# $NetBSD: Makefile,v 1.9 2012/10/03 18:15:32 asau Exp $
#

DISTNAME=	nmzmail-1.1
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/nmzmail.html
COMMENT=	Fast mail searching for mutt
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes

DEPENDS+=	namazu>=2.0.20:../../textproc/namazu

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
