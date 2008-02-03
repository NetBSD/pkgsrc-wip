# $NetBSD: Makefile,v 1.3 2008/02/03 12:00:08 shindenmorr Exp $
#

DISTNAME=	dsh-0.25.9
CATEGORIES=	shells
MASTER_SITES=	http://www.netfort.gr.jp/~dancer/software/downloads/

MAINTAINER=	shinden@linux.pl
HOMEPAGE=	http://www.netfort.gr.jp/~dancer/software/downloads/
COMMENT=	Runs command through rsh or ssh on a cluster of machines

PKG_DESTDIR_SUPPORT=	user-destdir
EGDIR=			${PREFIX}/share/examples/dsh
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
CONF_FILES=		${EGDIR}/dsh.conf ${PKG_SYSCONFDIR}/dsh.conf

.include "../../wip/libdshconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
