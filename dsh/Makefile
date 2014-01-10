# $NetBSD: Makefile,v 1.7 2014/01/10 21:13:45 cheusov Exp $
#

DISTNAME=	dsh-0.25.10
CATEGORIES=	shells
MASTER_SITES=	http://www.netfort.gr.jp/~dancer/software/downloads/

MAINTAINER=	morr@NetBSD.org
HOMEPAGE=	http://www.netfort.gr.jp/~dancer/software/downloads/
COMMENT=	Runs command through rsh or ssh on a cluster of machines
LICENSE=	gnu-gpl-v2

EGDIR=			${PREFIX}/share/examples/dsh
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONF_FILES=		${EGDIR}/dsh.conf ${PKG_SYSCONFDIR}/dsh.conf

.include "../../wip/libdshconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
