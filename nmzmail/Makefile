# $NetBSD: Makefile,v 1.8 2010/04/15 16:39:10 othyro Exp $
#

DISTNAME=	nmzmail-1.1
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ecademix.com/JohannesHofmann/nmzmail.html
COMMENT=	Fast mail searching for mutt
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes

DEPENDS+=	namazu>=2.0.20:../../textproc/namazu

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
