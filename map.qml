import QtQuick 2.0
import QtLocation 5.6
import QtPositioning 5.6

Item{
    Map{
        id:map
        anchors.fill: parent
        plugin: Plugin{
            name:"osm"
            PluginParameter{
                name:"osm.mapping.providersrepository.disabled"
                value:"true"
            }
            PluginParameter{
                name:"osm.mapping.providersrepository.address"
                value:"http://maps-redirect.qt.io/osm/5.6/"
            }

        }
        center: QtPositioning.coordinate(36.8065, 10.1815)
        zoomLevel: 15
    }
}
