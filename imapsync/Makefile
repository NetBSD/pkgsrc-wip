# $NetBSD: Makefile,v 1.2 2006/04/19 21:33:04 ahallmann Exp $
#

DISTNAME=		imapsync-${VERS}
CATEGORIES=		mail
MASTER_SITES=		http://www.linux-france.org/prj/imapsync/dist/
EXTRACT_SUFX=		.tgz

MAINTAINER=		hallmann@ahatec.de
HOMEPAGE=		http://www.linux-france.org/prj/imapsync
COMMENT=		Slow, memory intensive but great tool to sync and migrate imap servers

NAME=			imapsync
VERS=			1.156

REPLACE_PERL+=		imapsync
DEPENDS+=		p5-Mail-IMAPClient>=2.2.9nb2:../../mail/p5-Mail-IMAPClient
DEPENDS+=		p5-Digest-MD5>=2.33:../../security/p5-Digest-MD5
DEPENDS+=		p5-Digest-HMAC>=1.01:../../security/p5-Digest-HMAC
DEPENDS+=		p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey

MAKE_ENV+=		DESTDIR=${PREFIX:Q}

#post-install:
#        ${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${NAME}
#        ${INSTALL_DATA} ${WRKSRC}/learn/* ${PREFIX}/share/examples/${NAME}/

.include "../../mk/bsd.pkg.mk"
