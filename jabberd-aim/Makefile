# $NetBSD: Makefile,v 1.1.1.1 2004/03/27 22:38:10 xtraeme Exp $

DISTNAME=	aim-transport-stable-20040131
PKGNAME=	jabberd-aim-20040131
CATEGORIES=	chat
MASTER_SITES=	http://aim-transport.jabberstudio.org/

MAINTAINER=	david@netbsd-fr.org
COMMENT=	Jabber AIM Transport module

GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	YES
EXAMPLEFILE=	${PREFIX}/share/examples/jabberd/jabberd-aim.xml
MESSAGE_SUBST+=	EXAMPLEFILE=${EXAMPLEFILE}

CONFIGURE_ARGS+=	--with-jabberd=${PREFIX}/include/jabberd

pre-configure:
	if [ ! -h ${WRKDIR}/jabberd ]; then \
		${LN} -s ${PREFIX}/include/jabberd ${WRKDIR}/jabberd; \
	fi

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/aimtrans.so ${PREFIX}/lib/jabberd/
	${INSTALL_DATA} ${WRKSRC}/aim.xml ${EXAMPLEFILE}

.include "../../devel/pth/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../chat/jabberd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
