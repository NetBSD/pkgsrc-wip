# $NetBSD: Makefile,v 1.1 2013/02/07 17:04:30 jonperkin Exp $

DISTNAME=	libcouchbase-2.0.3
CATEGORIES=	devel
MASTER_SITES=	http://packages.couchbase.com/clients/c/

MAINTAINER=	trond.norbye@gmail.com
HOMEPAGE=	http://www.couchbase.com/develop/c/next
COMMENT=	C/C++ client library to access a Couchbase server
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake unzip
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--disable-couchbasemock
CONFIGURE_ARGS+=	--disable-static
# Test framework automatically downloads Google Test.
CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ENV+=		ac_cv_manpage_layout=bsd

.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
