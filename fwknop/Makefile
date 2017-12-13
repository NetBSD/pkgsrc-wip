# $NetBSD$

DISTNAME=	fwknop-2.6.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mrash/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/mrash/fwknop/
COMMENT=	Port knocking via Single Packet Authorization (SPA)
LICENSE=	gnu-gpl-v2

DEPENDS+=	gnupg-[0-9]*:../../security/gnupg
DEPENDS+=	wget-[0-9]*:../../net/wget

USE_TOOLS+=	aclocal autoconf automake autoheader
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/fwknop-2.6.9

pre-configure:
	cd ${WRKSRC} && sh autogen.sh

.include "../../net/libpcap/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
