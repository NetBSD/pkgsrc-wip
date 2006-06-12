# $NetBSD: Makefile,v 1.8 2006/06/12 16:42:55 thomasklausner Exp $
#

DISTNAME=	qico-0.48.5
CATEGORIES=	comms
MASTER_SITES=	http://lev.serebryakov.spb.ru/download/0.48/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	FidoNet mailer

USE_TOOLS+=	gmake

MAKE_ENV+=	SH=${SH:Q} AWK=${AWK:Q} MORDA=${QCC:Q}

.if defined(WITH_QCC)
QCC=		1
PLIST_SUBST=	QCC=""
.else
PLIST_SUBST=	QCC="@comment "
.endif

PKG_GROUPS=	news
PKG_USERS=	uucp:news

EGDIR=			${PREFIX}/share/examples/qico
CONF_FILES_PERMS=	${EGDIR}/qico.conf ${PKG_SYSCONFDIR}/qico.conf \
				uucp news 0644

RCD_SCRIPTS=	qico

post-configure:
	${SED} -e 's,@PREFIX@,${PREFIX},' \
	       -e 's,@AWK@,${AWK},' \
	       -e 's,@SH@,${SH},' \
	       -e 's,@INSTALL@,${INSTALL},' \
	       -e 's,@YACC@,${YACC},' \
	       -e 's,@LEX@,${LEX},' \
	       -e 's,@CC@,${CC},' \
	       -e 's,@MV@,${MV},' \
	       -e 's,@RM@,${RM},' \
	       -e 's,@ECHO@,${ECHO},' \
	       -e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},' ${WRKSRC}/CONFIG \
		> ${WRKSRC}/CONFIG-tmp
	${MV} -f ${WRKSRC}/CONFIG-tmp ${WRKSRC}/CONFIG

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/qico
	${INSTALL_DATA} ${WRKSRC}/qico.conf.sample \
		${PREFIX}/share/examples/qico/qico.conf

.include "../../mk/bsd.pkg.mk"
