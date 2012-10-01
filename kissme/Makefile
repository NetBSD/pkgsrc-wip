# $NetBSD: Makefile,v 1.6 2012/10/01 21:57:40 asau Exp $
#

DISTNAME=		kissme-0.0.32
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kissme/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://kissme.sourceforge.net/
COMMENT=		Java Virtual Machine (JVM) freely available

DEPENDS+=		classpath>=0.7:../../lang/classpath
DEPENDS+=		zip>=2.3:../../archivers/zip

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-classpath-install-dir=${PREFIX}/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
