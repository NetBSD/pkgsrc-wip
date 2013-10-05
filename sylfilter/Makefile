# $NetBSD: Makefile,v 1.2 2013/10/05 21:14:19 ishit Exp $
#

DISTNAME=	sylfilter-0.8
CATEGORIES=	mail
MASTER_SITES=	http://sylpheed.sraoss.jp/sylfilter/src/

MAINTAINER=	ishit@usrs.sorceforge.net
HOMEPAGE=	http://sylpheed.sraoss.jp/sylfilter/
COMMENT=	Bayesian spam filter
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config

CONFIGURE_ARGS+=	--with-libsylph=standalone
#CONFIGURE_ARGS+=	--with-libsylph-dir=

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/libsylph/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
