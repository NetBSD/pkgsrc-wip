# $NetBSD: Makefile,v 1.1.1.1 2004/01/04 02:06:32 jeremy-c-reed Exp $

# XXX This uses the version of apache2 distfile instead of
# XXX the AP_AB_BASEREVISION from the support/ab.c source.
PKGNAME=		ab-${APACHE_VERSION}
CATEGORIES=		benchmarks www

HOMEPAGE=		http://httpd.apache.org/
COMMENT=		Apache HTTP (Web) server benchmarking tool

CONFLICTS=		apache-*ssl-[0-9]* apache-[0-9]* apache6-[0-9]*
CONFLICTS+=		apache2-[0-9]*

BUILD_DEFS+=		USE_INET6

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES

#USE_LIBTOOL=		YES
#LIBTOOL_OVERRIDE=	${WRKSRC}/srclib/apr/libtool

GNU_CONFIGURE=		YES

# Apache Portable Runtime library configure options
CONFIGURE_ARGS+=	--with-apr=${LOCALBASE}
CONFIGURE_ARGS+=	--with-apr-util=${LOCALBASE}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--enable-static-ab
# ab_LTFLAGS="-static"

do-build:
	cd ${WRKSRC}/support && ${MAKE} ab

#do-install:
# need to install sbin/ab and man8/ab.8

.include "../../www/apache2/Makefile.common"

.include "../../security/openssl/buildlink2.mk"
.include "../../devel/apr/buildlink2.mk"
#.include "../../lang/perl5/buildlink2.mk"
#.include "../../textproc/expat/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
