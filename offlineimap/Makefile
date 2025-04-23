# $NetBSD: Makefile,v 1.42 2024/08/14 17:25:21 wiz Exp $

DISTNAME=	offlineimap3-8.0.0.2024.08.26
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=OfflineIMAP/}
# 8.0.0 is 4 years old, so use snapshot
GITHUB_TAG=	db347452273bb0f1b1a8ea952f6fb46cf95fedbf

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OfflineIMAP/offlineimap3
COMMENT=	Powerful IMAP/Maildir synchronization and reader support (v3)
LICENSE=	gnu-gpl-v2 # or later

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-rfc6555-[0-9]*:../../net/py-rfc6555
DEPENDS+=	${PYPKGPREFIX}-imaplib2>=3.5:../../wip/py-imaplib2
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.9:../../www/py-urllib3

INSTALLATION_DIRS=	share/examples/offlineimap

CONFLICTS+=	offlineimap-[0-9]*

post-install:
.for f in offlineimap.conf offlineimap.conf.minimal
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/share/examples/offlineimap/${f}
.endfor

WHEEL_NAME=	offlineimap-8.0.0

# needs imap credentials for testing:
# as of 8.0.0.2024.08.26
# 1 warning, 1 error

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
