# $NetBSD: Makefile,v 1.1.1.1 2004/06/08 07:51:12 cjep Exp $
#

DISTNAME=	argus-3.2.1
CATEGORIES= 	net
MASTER_SITES=	http://www.tcp4me.com/code/argus-archive/
EXTRACT_SUFX=	.tgz

MAINTAINER=	argus@tcp4me.com
HOMEPAGE=	http://argus.tcp4me.com/
COMMENT=	System and Network Monitoring Application

DEPENDS+= perl-5*:../../lang/perl5	# needed.
DEPENDS+= fping>=2.4b2:../../net/fping	# needed.
DEPENDS+= p5-GD>=2.11:../../graphics/p5-GD	# needed if you want graphs
DEPENDS+= p5-Socket6>=0.12:../../net/p5-Socket6	# needed if you want to use IPv6

HAS_CONFIGURE= 		1
CONFIGURE_SCRIPT=	${WRKSRC}/Configure

CONFIGURE_ARGS+=	--bin_dir  ${PREFIX}/bin
CONFIGURE_ARGS+=	--sbin_dir ${PREFIX}/sbin
CONFIGURE_ARGS+=	--lib_dir  ${PREFIX}/lib/argus
CONFIGURE_ARGS+=	--data_dir /var/argus

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes

.include "../../mk/bsd.prefs.mk"

RCD_SCRIPTS=		argusd

.include "../../mk/bsd.pkg.mk"
