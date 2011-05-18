# $NetBSD: Makefile,v 1.11 2011/05/18 19:23:12 alnsn Exp $
#

DISTNAME=		pcapy-0.10.5
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=	http://oss.corest.com/repo/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://oss.corest.com/projects/pcapy.html
COMMENT=		Python interface to pcap library
LICENSE=		apache-1.1

USE_LANGUAGES+=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

BUILDLINK_API_DEPENDS.libpcap+=	libpcap>=0.7.2

.include "../../lang/python/extension.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
