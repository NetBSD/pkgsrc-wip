# $NetBSD: Makefile,v 1.3 2004/07/06 22:01:25 thomasklausner Exp $
#

DISTNAME=		pcapy-0.10.2
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		net
MASTER_SITES=		http://oss.corest.com/repo/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://oss.corest.com/projects/pcapy.html
COMMENT=		Python interface to pcap library

USE_BUILDLINK3=		yes
PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes

PYTHON_VERSIONS_ACCEPTED=	23 22 23pth 22pth

.include "../../lang/python/extension.mk"

###########################################################################
# WARNING!
# 
# this is only temporary solution because of braindead buildlink3.mk
# "autoconfiguration"; on 1.6.1-stable system this will _not_ build just
# because -stable has too old pcap library.
###########################################################################

BUILD_DEPENDS+=		libpcap>=0.7.2:../../net/libpcap
BUILDLINK_PACKAGES+=	libpcap
EVAL_PREFIX+=		BUILDLINK_PREFIX.libpcap=libpcap
BUILDLINK_PREFIX.libpcap_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.libpcap=	include/pcap.h
BUILDLINK_FILES.libpcap+=	include/pcap-namedb.h
BUILDLINK_FILES.libpcap+=	include/net/bpf.h
BUILDLINK_FILES.libpcap+=	lib/libpcap.*
BUILDLINK_TARGETS+=	libpcap-buildlink
libpcap-buildlink: _BUILDLINK_USE

#
# If the buildlink wasn't broken, I could use this: 
#
# .include "../../net/libpcap/buildlink3.mk"
#

.include "../../mk/bsd.pkg.mk"
