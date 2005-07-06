# $NetBSD: Makefile,v 1.4 2005/07/06 16:40:37 leonardschmidt Exp $
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

SUBST_CLASSES+=	paths
SUBST_MESSAGE.paths=	"Fixing hardcoded paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	sample.esmtprc esmtprc.5
SUBST_SED.paths=	-e 's,/usr/bin,${LOCALBASE}/bin,g'

PTHREAD_OPTS+=	require

EGDIR=	${PREFIX}/share/examples/esmtp

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.esmtprc ${EGDIR}

.include "../../mail/libesmtp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
