# $NetBSD: Makefile,v 1.2 2004/01/25 09:28:40 minskim Exp $

DISTNAME=	ipgrab-0.9.8
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ipgrab/}

MAINTAINER=	minskim@bawi.org
HOMEPAGE=	http://ipgrab.sourceforge.net/
COMMENT=	Verbose packet sniffer for UNIX hosts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_MAKEINFO=	yes
INFO_FILES=	ipgrab.info

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
