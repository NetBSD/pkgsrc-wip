# $NetBSD: Makefile,v 1.9 2006/05/07 14:00:36 jtonio Exp $
#

.include "Makefile.common"

CONFLICTS+=		kaffe-nox11-[0-9]*

CONFIGURE_ARGS+=	--disable-native-awt
CONFIGURE_ARGS+=	--disable-gtk-peer
CONFIGURE_ARGS+=	--without-x

JAVA_WRAPPERS=		appletviewer jar java javac javadoc javah javakey \
			javap jdb rmic rmiregistry serialver

CONF_FILES=		${JAVA_HOME}/jre/lib/security/java.security.default \
			${JAVA_HOME}/jre/lib/security/java.security

.include "../../mk/bsd.prefs.mk"

UNLIMIT_RESOURCES=        datasize
LIBS+= -lltdl

PRINT_PLIST_AWK+=	/^java\/kaffe\/jre\/lib\/security\/java.security$$/ \
				{ next; }

post-install:
	${INSTALL_DATA} ${WRKSRC}/license.terms ${JAVA_HOME}

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
