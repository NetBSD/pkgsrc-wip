# $NetBSD: Makefile,v 1.1.1.1 2005/04/06 19:43:03 ura Exp $

DISTNAME=	im-147
CATEGORIES=	mail
MASTER_SITES=	http://tats.haun.org/im/ \
		${MASTER_SITE_PORTS_JP}

MAINTAINER=	ura@jp.NetBSD.org
HOMEPAGE=	http://tats.haun.org/im/
COMMENT=	Set of user interfaces of Email and NetNews

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --libdir=${PREFIX}/etc
# If you use RPOP instead of APOP, comment out following line.
#CONFIGURE_ARGS+=--enable-rpop
MAKE_ARGS=	prefix=${PREFIX} imlibdir=${PREFIX}/etc/im

DOCDIR=		${PREFIX}/share/doc/im
EXAMPLEDIR=	${PREFIX}/share/examples/im
DOCS=		00changes 00copyright 00copyright.jis 00perl 00readme 00usage
MAN=		imput
MAN_JA=		imali.jis imcat.jis imcd.jis imclean.jis imget.jis	\
		imhist.jis imjoin.jis immv.jis impack.jis imput.jis	\
		imrm.jis imsetup.jis imsort.jis imstore.jis imtar.jis

post-install:
	@${INSTALL_DATA_DIR} ${DOCDIR}/man/ja
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCDIR}
.endfor
.for FILE in ${MAN}
	${INSTALL_DATA} ${WRKSRC}/man/${FILE} ${DOCDIR}/man
.endfor
.for FILE in ${MAN_JA}
	${INSTALL_DATA} ${WRKSRC}/man/${FILE} ${DOCDIR}/man/ja
.endfor
	@${INSTALL_DATA_DIR} ${EXAMPLEDIR}
	${CP} -r ${WRKSRC}/dot.im/ ${EXAMPLEDIR}

.include "../../mk/bsd.pkg.mk"
