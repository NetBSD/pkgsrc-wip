# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:24 othyro Exp $
#

DISTNAME=		kissme-0.0.32
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=kissme/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kissme.sourceforge.net/
COMMENT=		Java Virtual Machine (JVM) freely available

DEPENDS+=		classpath>=0.7:../../lang/classpath
DEPENDS+=		zip>=2.3:../../archivers/zip


USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-classpath-install-dir=${PREFIX}/

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
