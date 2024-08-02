#include "../../jc2dpch.h"
#include "layer_stack.h"
#include "../logger/logger.h"
namespace JC2D {
    void LayerStack::initLayers() {
        for (Layer* layer : m_layers) {
            layer->onAttach();
        }
    }

    LayerStack::~LayerStack() {
        for (Layer* layer : m_layers) {
            layer->onDetach();
            delete layer;
        }
    }

    void LayerStack::pushLayer(Layer* layer) {
        m_layers.insert(m_layers.begin() + m_layerInsertIndex, layer);
        m_layerInsertIndex++;
    }

    void LayerStack::pushOverlay(Layer* overlay) {
        m_layers.push_back(overlay);
    }

    void LayerStack::popLayer(Layer* layer) {
        auto it = std::find(m_layers.begin(), m_layers.begin() + m_layerInsertIndex, layer);
        if (it != m_layers.begin() + m_layerInsertIndex) {
            layer->onDetach();
            m_layers.erase(it);
            m_layerInsertIndex--;
        }
    }

    void LayerStack::popOverlay(Layer* overlay) {
        auto it = std::find(m_layers.begin() + m_layerInsertIndex, m_layers.end(), overlay);
        if (it != m_layers.end()) {
            overlay->onDetach();
            m_layers.erase(it);
        }
    }

}  // namespace JC2D