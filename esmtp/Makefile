# $NetBSD: Makefile,v 1.1.1.1 2005/05/24 09:19:51 leonardschmidt Exp $
#

DISTNAME=	esmtp-0.5.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=esmtp/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://esmtp.sourceforge.net/
COMMENT=	Relay-only Mail Transfer Agent with sendmail compatible syntax

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

GNU_CONFIGURE=	yes

EGDIR=	${PREFIX}/share/examples/esmtp

post-patch:
	${SED} 's|/usr/bin|${LOCALBASE}/bin|g' \
		${WRKSRC}/sample.esmtprc > ${WRKSRC}/sample.esmtprc.new

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.esmtprc.new ${EGDIR}/sample.esmtprc

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
